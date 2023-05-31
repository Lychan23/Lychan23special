// Set up the canvas
const canvas = document.getElementById("flappy-bird");
const context = canvas.getContext("2d");

// Set up colors
const bgColor = "#70c5ce";
const birdColor = "#ff6e40";
const pipeColor = "#004080";

// Set up bird dimensions
const birdSize = 30;
const birdX = canvas.width / 4;
let birdY = canvas.height / 2;

// Set up pipe dimensions and gap
const pipeWidth = 80;
const pipeGap = 150;
const pipeSpeed = 2;
let pipes = [];

// Set up game state
let score = 0;
let isGameOver = false;

// Set up keyboard controls
document.addEventListener("keydown", function (event) {
  if (event.keyCode === 87) {
    // W key
    birdY -= 50;
  } else if (event.keyCode === 83) {
    // S key
    birdY += 50;
  }
});

// Generate a new pipe
function generatePipe() {
  const pipe = {
    x: canvas.width,
    y: Math.floor(Math.random() * (canvas.height - pipeGap * 2) + pipeGap),
    width: pipeWidth,
    height: canvas.height - pipeGap * 2,
  };
  pipes.push(pipe);
}

// Update game state
function update() {
  // Move bird
  birdY += 2;

  // Move pipes
  for (let i = 0; i < pipes.length; i++) {
    pipes[i].x -= pipeSpeed;

    // Check if bird collided with a pipe
    if (
      birdX + birdSize > pipes[i].x &&
      birdX < pipes[i].x + pipes[i].width &&
      (birdY < pipes[i].y || birdY + birdSize > pipes[i].y + pipes[i].height)
    ) {
      gameOver();
    }

    // Check if bird passed a pipe
    if (pipes[i].x + pipes[i].width < birdX && !pipes[i].scored) {
      pipes[i].scored = true;
      score++;
    }

    // Remove pipes that are off-screen
    if (pipes[i].x + pipes[i].width < 0) {
      pipes.splice(i, 1);
      i--;
    }
  }

  // Check if bird collided with the top or bottom of the canvas
  if (birdY < 0 || birdY + birdSize > canvas.height) {
    gameOver();
  }

  // Generate new pipes
  if (pipes.length === 0 || canvas.width - pipes[pipes.length - 1].x > 200) {
    generatePipe();
  }
}

// Render game elements
function render() {
  // Clear the canvas
  context.fillStyle = bgColor;
  context.fillRect(0, 0, canvas.width, canvas.height);

  // Draw bird
  context.fillStyle = birdColor;
  context.fillRect(birdX, birdY, birdSize, birdSize);

  // Draw pipes
  context.fillStyle = pipeColor;
  for (let i = 0; i < pipes.length; i++) {
    context.fillRect(pipes[i].x, 0, pipes[i].width, pipes[i].y);
    context.fillRect(pipes[i].x, pipes[i].y + pipes[i].height, pipes[i].width, canvas.height - pipes[i].y - pipes[i].height);
  }

  // Draw score
  context.fillStyle = "#fff";
  context.font = "24px Arial";
  context.fillText("Score: " + score, 10, 30);

  // Draw game over message
  if (isGameOver) {
    context.fillStyle = "#fff";
    context.font = "36px Arial";
    context.fillText("Game Over", canvas.width / 2 - 100, canvas.height / 2);
  }
}

// Game loop
function gameLoop() {
  update();
  render();
  if (!isGameOver) {
    requestAnimationFrame(gameLoop);
  }
}

// Game over logic
function gameOver() {
  isGameOver = true;
}

// Start the game loop
gameLoop();
