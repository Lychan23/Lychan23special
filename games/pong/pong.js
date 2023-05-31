// Set up the canvas
const canvas = document.getElementById("pong");
const context = canvas.getContext("2d");

// Set up colors
const bgColor = "#000";
const paddleColor = "#fff";
const ballColor = "#fff";

// Set up paddle dimensions
const paddleWidth = 10;
const paddleHeight = 60;
const paddleGap = 10;

// Set up ball dimensions
const ballSize = 10;

// Set up initial paddle positions
let player1Y = canvas.height / 2 - paddleHeight / 2;
let player2Y = canvas.height / 2 - paddleHeight / 2;

// Set up initial ball position and velocity
let ballX = canvas.width / 2;
let ballY = canvas.height / 2;
let ballSpeedX = 3;
let ballSpeedY = 3;

// Set up score variables
let player1Score = 0;
let player2Score = 0;

// Move paddles based on keyboard input
document.addEventListener("keydown", function (event) {
  if (event.keyCode === 38) {
    // Up arrow key
    player2Y -= 10;
  } else if (event.keyCode === 40) {
    // Down arrow key
    player2Y += 10;
  } else if (event.keyCode === 87) {
    // W key
    player1Y -= 10;
  } else if (event.keyCode === 83) {
    // S key
    player1Y += 10;
  }
});

// Update game state
function update() {
  // Move the ball
  ballX += ballSpeedX;
  ballY += ballSpeedY;

  // Check ball collision with walls
  if (ballY < 0 || ballY + ballSize > canvas.height) {
    ballSpeedY *= -1;
  }

  // Check ball collision with paddles
  if (
    ballX - ballSize < paddleWidth &&
    ballY + ballSize > player1Y &&
    ballY - ballSize < player1Y + paddleHeight
  ) {
    ballSpeedX *= -1;
  }

  if (
    ballX + ballSize > canvas.width - paddleWidth &&
    ballY + ballSize > player2Y &&
    ballY - ballSize < player2Y + paddleHeight
  ) {
    ballSpeedX *= -1;
  }

  // Check if a player scored
  if (ballX < 0) {
    player2Score++;
    reset();
  } else if (ballX + ballSize > canvas.width) {
    player1Score++;
    reset();
  }
}

// Reset the ball position and velocity
function reset() {
  ballX = canvas.width / 2;
  ballY = canvas.height / 2;
  ballSpeedX = 3;
  ballSpeedY = 3;
}

// Render game elements
function render() {
  // Clear the canvas
  context.fillStyle = bgColor;
  context.fillRect(0, 0, canvas.width, canvas.height);

  // Draw paddles
  context.fillStyle = paddleColor;
  context.fillRect(paddleGap, player1Y, paddleWidth, paddleHeight);
  context.fillRect(
    canvas.width - paddleWidth - paddleGap,
    player2Y,
    paddleWidth,
    paddleHeight
  );

  // Draw ball
  context.fillStyle = ballColor;
  context.beginPath();
  context.arc(ballX, ballY, ballSize, 0, Math.PI * 2, false);
  context.closePath();
  context.fill();

  // Draw scores
  context.fillStyle = "#fff";
  context.font = "24px Arial";
  context.fillText(player1Score, canvas.width / 4, 30);
  context.fillText(player2Score, (canvas.width * 3) / 4, 30);
}

// Game loop
function gameLoop() {
  update();
  render();
  requestAnimationFrame(gameLoop);
}

// Start the game loop
gameLoop();
