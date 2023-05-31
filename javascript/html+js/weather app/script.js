document.getElementById("getWeatherBtn").addEventListener("click", function() {
    var cityName = document.getElementById("city").value;
    if (cityName.trim() === "") {
      alert("Please enter a city name");
      return;
    }
  
    // Make a request to the weather API
    var url = "https://api.open-meteo.com/v1/forecast?city=" + cityName;
  
    fetch(url)
      .then(function(response) {
        return response.json();
      })
      .then(function(data) {
        // Display the weather information
        var weatherInfo = document.getElementById("weatherInfo");
        weatherInfo.innerHTML = "";
  
        var city = document.createElement("h2");
        city.textContent = data.city.name + ", " + data.city.country;
        weatherInfo.appendChild(city);
  
        var temperature = document.createElement("p");
        temperature.textContent = "Temperature: " + data.current_temperature + "°C";
        weatherInfo.appendChild(temperature);
  
        var condition = document.createElement("p");
        condition.textContent = "Condition: " + data.weather.description;
        weatherInfo.appendChild(condition);
  
        var humidity = document.createElement("p");
        humidity.textContent = "Humidity: " + data.humidity + "%";
        weatherInfo.appendChild(humidity);
      })
      .catch(function(error) {
        console.log("Error:", error);
      });
  });
  