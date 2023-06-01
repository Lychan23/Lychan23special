document.addEventListener("DOMContentLoaded", () => {
    const player = document.getElementById("player");
    const platforms = Array.from(document.getElementsByClassName("platform"));
  
    let isJumping = false;
    let jumpTimer;
    let gravity = 0.5;
    let playerBottom = 200; // Adjust the starting position
    let playerLeft = 0;
    let isGameOver = false;
    let isMovingLeft = false;
    let isMovingRight = false;
  
    function startGame() {
      if (isGameOver) return;
      playerBottom = 200; // Adjust the starting position
      playerLeft = 0;
      isJumping = false;
      jumpTimer = null;
      player.style.bottom = playerBottom + "px";
      player.style.left = playerLeft + "px";
      movePlatforms();
      document.addEventListener("keydown", handleKeyDown);
      document.addEventListener("keyup", handleKeyUp);
      gameLoop();
    }
  
    function movePlatforms() {
      // ...
    }
  
    function handleKeyDown(event) {
      if (event.code === "Space" && !isJumping) {
        jump();
      }
      if (event.code === "ArrowLeft") {
        isMovingLeft = true;
      }
      if (event.code === "ArrowRight") {
        isMovingRight = true;
      }
    }
  
    function handleKeyUp(event) {
      if (event.code === "ArrowLeft") {
        isMovingLeft = false;
      }
      if (event.code === "ArrowRight") {
        isMovingRight = false;
      }
    }
  
    function jump() {
      // ...
    }
  
    function fall() {
      // ...
    }
  
    function gameLoop() {
      if (isGameOver) return;
  
      // Move player left or right based on key input
      if (isMovingLeft) {
        moveLeft();
      }
      if (isMovingRight) {
        moveRight();
      }
  
      // Check collision with each platform
      const playerRect = player.getBoundingClientRect();
      platforms.forEach((platform) => {
        const platformRect = platform.getBoundingClientRect();
  
        if (isColliding(playerRect, platformRect)) {
          handleCollision();
        }
      });
  
      requestAnimationFrame(gameLoop);
    }
  
    function moveLeft() {
      playerLeft -= 5;
      player.style.left = playerLeft + "px";
    }
  
    function moveRight() {
      playerLeft += 5;
      player.style.left = playerLeft + "px";
    }
  
    function isColliding(rect1, rect2) {
      // ...
    }
  
    function handleCollision() {
      isGameOver = true;
      document.removeEventListener("keydown", handleKeyDown);
      document.removeEventListener("keyup", handleKeyUp);
      alert("Game Over");
    }
  
    startGame();
  });
  