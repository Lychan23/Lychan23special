fetch('https://api.example.com/data')
  .then(function(response) {
    if (response.ok) {
      return response.json();
    }
    throw new Error('Network response was not ok.');
  })
  .then(function(data) {
    // Handle the response data here
  })
  .catch(function(error) {
    // Handle any errors that occurred during the request
  });
