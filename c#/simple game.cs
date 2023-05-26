using System;

class Character
{
    public string Name { get; set; }
    public int Health { get; set; }
    public int AttackPower { get; set; }

    public Character(string name)
    {
        Name = name;
        Health = 100;
        AttackPower = 10;
    }

    public void Attack(Character enemy)
    {
        int damage = AttackPower;
        enemy.Health -= damage;
        Console.WriteLine($"{Name} attacks {enemy.Name} and deals {damage} damage.");

        if (enemy.Health <= 0)
        {
            Console.WriteLine($"{enemy.Name} has been defeated!");
        }
    }
}

class Game
{
    private Character player;

    public void Start()
    {
        Console.WriteLine("Welcome to the Text-based RPG!");

        Console.Write("Enter your character name: ");
        string playerName = Console.ReadLine();
        player = new Character(playerName);

        Console.WriteLine($"Welcome, {player.Name}! Let's start your adventure.");

        ExploreWorld();
    }

    private void ExploreWorld()
    {
        while (true)
        {
            Console.WriteLine("\n---- World Map ----");
            Console.WriteLine("1. Battle");
            Console.WriteLine("2. Quest");
            Console.WriteLine("3. Exit");
            Console.Write("Enter your choice: ");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Battle();
                    break;
                case "2":
                    Quest();
                    break;
                case "3":
                    Console.WriteLine("Thank you for playing. Goodbye!");
                    return;
                default:
                    Console.WriteLine("Invalid choice. Try again.");
                    break;
            }
        }
    }

    private void Battle()
    {
        Console.WriteLine("\n---- Battle ----");
        Console.Write("Enter the enemy name: ");
        string enemyName = Console.ReadLine();
        Character enemy = new Character(enemyName);

        while (player.Health > 0 && enemy.Health > 0)
        {
            Console.WriteLine($"\n{player.Name} (Health: {player.Health}) vs. {enemy.Name} (Health: {enemy.Health})");
            Console.WriteLine("1. Attack");
            Console.WriteLine("2. Run");
            Console.Write("Enter your choice: ");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    player.Attack(enemy);
                    break;
                case "2":
                    Console.WriteLine("You run away from the battle!");
                    return;
                default:
                    Console.WriteLine("Invalid choice. Try again.");
                    break;
            }

            if (enemy.Health > 0)
            {
                enemy.Attack(player);
            }
        }

        Console.WriteLine("Battle ends.");
    }

    private void Quest()
    {
        Console.WriteLine("\n---- Quest ----");
        Console.WriteLine("Quest not implemented yet. Stay tuned for updates!");
    }
}

class gamecs
{
    static void Main(string[] args)
    {
        Game game = new Game();
        game.Start();
    }
}
