import string
import random

def generate_password(length, characters):
    """Generate a random password based on the given length and characters."""
    password = ' ' + ''.join(random.choice(characters) for _ in range(length-1))
    return password

def save_password(password, output_file):
    """Save the generated password by appending it to the specified output file."""
    with open(output_file, 'a') as file:
        file.write(password + '\n')

def main():
    # User-defined criteria
    length = int(input("Enter the desired password length: "))
    characters = string.ascii_letters + string.digits + string.punctuation

    # Generate the password
    password = generate_password(length, characters)

    # Save the password in the output file
    output_file = 'output/password.txt'
    save_password(password, output_file)
    print(f"Generated password: {password}")
    print(f"Password saved in {output_file}")

if __name__ == '__main__':
    main()
