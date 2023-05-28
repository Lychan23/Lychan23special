#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
using namespace std;

// Structure for a Huffman tree node
struct Node {
    char data;
    unsigned freq;
    Node* left;
    Node* right;
};

// Comparator for the priority queue
struct Compare {
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

// Function to create a new Huffman tree node
Node* getNode(char data, unsigned freq, Node* left, Node* right)
{
    Node* node = new Node();
    node->data = data;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Traverses the Huffman tree and stores Huffman codes
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Builds the Huffman tree and generates Huffman codes
void buildHuffmanTree(string text, unordered_map<char, string>& huffmanCode)
{
    // Count the frequency of each character
    unordered_map<char, unsigned> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store the nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // Build the Huffman tree
    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        unsigned sumFreq = left->freq + right->freq;
        pq.push(getNode('\0', sumFreq, left, right));
    }

    // Traverse the Huffman tree and store Huffman codes
    encode(pq.top(), "", huffmanCode);
}

// Compresses the input file using Huffman coding
void compressFile(const string& inputFile, const string& outputFile)
{
    ifstream input(inputFile, ios::binary);
    ofstream output(outputFile, ios::binary);

    // Read the input file
    string text;
    char ch;
    while (input.get(ch)) {
        text += ch;
    }

    unordered_map<char, string> huffmanCode;
    buildHuffmanTree(text, huffmanCode);

    // Write the Huffman-encoded data to the output file
    for (char ch : text) {
        output << huffmanCode[ch];
    }

    input.close();
    output.close();

    cout << "File compressed successfully!" << endl;
}

int main()
{
    string inputFile = "input.txt";
    string compressedFile = "compressed.bin";

    compressFile(inputFile, compressedFile);

    return 0;
}
