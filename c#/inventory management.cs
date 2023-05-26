using System;
using System.Collections.Generic;

class Product
{
    public string Name { get; set; }
    public int Quantity { get; set; }
}

class InventoryManagementSystem
{
    private Dictionary<string, Product> products;

    public InventoryManagementSystem()
    {
        products = new Dictionary<string, Product>();
    }

    public void AddProduct(string name, int quantity)
    {
        if (products.ContainsKey(name))
        {
            Console.WriteLine("Product already exists.");
        }
        else
        {
            Product product = new Product { Name = name, Quantity = quantity };
            products.Add(name, product);
            Console.WriteLine("Product added successfully.");
        }
    }

    public void UpdateStock(string name, int quantity)
    {
        if (products.ContainsKey(name))
        {
            Product product = products[name];
            product.Quantity = quantity;
            Console.WriteLine("Stock updated successfully.");
        }
        else
        {
            Console.WriteLine("Product does not exist.");
        }
    }

    public void GenerateInventoryReport()
    {
        Console.WriteLine("Inventory Report:");
        foreach (var product in products.Values)
        {
            Console.WriteLine($"Product: {product.Name}, Quantity: {product.Quantity}");
        }
    }
}

class invmanager
{
    static void Main(string[] args)
    {
        InventoryManagementSystem inventorySystem = new InventoryManagementSystem();

        // Add some initial products
        inventorySystem.AddProduct("Product A", 10);
        inventorySystem.AddProduct("Product B", 5);
        inventorySystem.AddProduct("Product C", 15);

        // Update stock levels
        inventorySystem.UpdateStock("Product B", 8);

        // Generate inventory report
        inventorySystem.GenerateInventoryReport();
    }
}
