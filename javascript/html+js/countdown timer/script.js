// Get the target date and time from the input
const dateInput = document.getElementById("date");
const startBtn = document.getElementById("startBtn");
const countdownDisplay = document.getElementById("countdown");

startBtn.addEventListener("click", function() {
  const targetDate = new Date(dateInput.value).getTime();

  // Start the countdown
  startCountdown(targetDate);
});

function startCountdown(targetDate) {
  // Update the countdown every second
  const countdownTimer = setInterval(updateCountdown, 1000);

  function updateCountdown() {
    const currentTime = new Date().getTime();
    const timeDifference = targetDate - currentTime;

    if (timeDifference <= 0) {
      // Countdown completed
      clearInterval(countdownTimer);
      countdownDisplay.textContent = "Countdown completed!";
      // Add any additional actions or notifications here
    } else {
      // Calculate remaining days, hours, minutes, and seconds
      const days = Math.floor(timeDifference / (1000 * 60 * 60 * 24));
      const hours = Math.floor((timeDifference % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
      const minutes = Math.floor((timeDifference % (1000 * 60 * 60)) / (1000 * 60));
      const seconds = Math.floor((timeDifference % (1000 * 60)) / 1000);

      // Display the countdown
      countdownDisplay.innerHTML = `Time remaining: ${days}d ${hours}h ${minutes}m ${seconds}s`;
    }
  }
}
