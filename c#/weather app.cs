using System;
using System.Net.Http;
using System.Threading.Tasks;

class appweather
{
    static async Task Main()
    {
        Console.Write("Enter the city name: ");
        string city = Console.ReadLine();

        try
        {
            WeatherData weatherData = await GetWeatherData(city);
            if (weatherData != null)
            {
                Console.WriteLine($"City: {weatherData.Name}");
                Console.WriteLine($"Temperature: {weatherData.Main.Temp}°C");
                Console.WriteLine($"Humidity: {weatherData.Main.Humidity}%");
                Console.WriteLine($"Weather: {weatherData.Weather[0].Description}");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }
    }

    static async Task<WeatherData> GetWeatherData(string city)
    {
        string apiKey = "YOUR_API_KEY";
        string apiUrl = $"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={apiKey}&units=metric";

        using (HttpClient client = new HttpClient())
        {
            HttpResponseMessage response = await client.GetAsync(apiUrl);
            if (response.IsSuccessStatusCode)
            {
                WeatherData weatherData = await response.Content.ReadAsAsync<WeatherData>();
                return weatherData;
            }
            else
            {
                throw new Exception("Unable to fetch weather data. Please try again.");
            }
        }
    }
}

class WeatherData
{
    public string Name { get; set; }
    public Weather[] Weather { get; set; }
    public MainData Main { get; set; }
}

class Weather
{
    public string Description { get; set; }
}

class MainData
{
    public double Temp { get; set; }
    public int Humidity { get; set; }
}
