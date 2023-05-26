using System;
using System.IO;

class FileExplorer
{
    static void Main()
    {
        string currentDirectory = Directory.GetCurrentDirectory();
        ExploreDirectory(currentDirectory);
    }

    static void ExploreDirectory(string path)
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine("Current Directory: " + path);
            Console.WriteLine("\n[.] - Current Directory");
            Console.WriteLine("[..] - Parent Directory\n");

            string[] directories = Directory.GetDirectories(path);
            string[] files = Directory.GetFiles(path);

            int index = 1;
            foreach (var directory in directories)
            {
                string directoryName = new DirectoryInfo(directory).Name;
                Console.WriteLine("[" + index + "] - " + directoryName);
                index++;
            }

            foreach (var file in files)
            {
                string fileName = new FileInfo(file).Name;
                Console.WriteLine("[" + index + "] - " + fileName);
                index++;
            }

            Console.WriteLine("\n[q] - Quit\n");

            Console.Write("Enter your choice: ");
            string choice = Console.ReadLine();

            if (choice == "q")
                break;

            if (choice == ".")
            {
                ExploreDirectory(path);
                continue;
            }

            if (choice == "..")
            {
                DirectoryInfo parentDirectory = Directory.GetParent(path);
                if (parentDirectory != null)
                {
                    path = parentDirectory.FullName;
                    ExploreDirectory(path);
                }
                continue;
            }

            if (int.TryParse(choice, out int selection))
            {
                if (selection >= 1 && selection <= directories.Length)
                {
                    path = directories[selection - 1];
                    ExploreDirectory(path);
                }
                else if (selection > directories.Length && selection <= directories.Length + files.Length)
                {
                    string file = files[selection - 1 - directories.Length];
                    Console.Clear();
                    Console.WriteLine("File Name: " + new FileInfo(file).Name);
                    Console.WriteLine("File Size: " + new FileInfo(file).Length + " bytes");
                    Console.WriteLine("Creation Time: " + new FileInfo(file).CreationTime);
                    Console.WriteLine("Last Accessed Time: " + new FileInfo(file).LastAccessTime);
                    Console.WriteLine("\n[d] - Delete File");
                    Console.WriteLine("[m] - Move File");
                    Console.WriteLine("[c] - Copy File");
                    Console.WriteLine("\n[p] - Go Back to Parent Directory");

                    Console.Write("\nEnter your choice: ");
                    string fileOption = Console.ReadLine();

                    if (fileOption == "d")
                    {
                        File.Delete(file);
                        Console.WriteLine("File deleted successfully.");
                    }
                    else if (fileOption == "m")
                    {
                        Console.Write("Enter destination path: ");
                        string destination = Console.ReadLine();
                        File.Move(file, destination);
                        Console.WriteLine("File moved successfully.");
                    }
                    else if (fileOption == "c")
                    {
                        Console.Write("Enter destination path: ");
                        string destination = Console.ReadLine();
                        File.Copy(file, destination);
                        Console.WriteLine("File copied successfully.");
                    }
                    else if (fileOption == "p")
                    {
                        ExploreDirectory(path);
                    }

                    Console.WriteLine("\nPress any key to continue...");
                    Console.ReadKey();
                }
            }
        }
    }
}
