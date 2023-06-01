// Tower Class
class Tower {
    constructor(type, range, power, fireRate) {
      this.type = type;
      this.range = range;
      this.power = power;
      this.fireRate = fireRate;
    }
  
    // Other methods for tower actions and behaviors
    // ...
  }
  
  // Tower Types
  const towerTypes = [
    new Tower("Basic Tower", 100, 10, 1),
    new Tower("Sniper Tower", 200, 30, 0.5),
    new Tower("Splash Tower", 80, 5, 2),
    new Tower("Slow Tower", 120, 0, 1),
    new Tower("Multi-Shot Tower", 150, 15, 0.8),
  ];
  
  // Game Logic
  function playTowerDefenseGame() {
    // Game initialization and setup
    // ...
  
    // Tower placement logic
    function placeTower(x, y, towerType) {
      // Place the tower on the game board at position (x, y) with the specified tower type
      // ...
    }
  
    // Example usage of placing towers
    placeTower(2, 3, towerTypes[0]); // Place a basic tower at position (2, 3)
    placeTower(5, 2, towerTypes[1]); // Place a sniper tower at position (5, 2)
    // ...
  
    // Game loop and other gameplay mechanics
    // ...
  }
  
  // Start the Tower Defense Game
  playTowerDefenseGame();
  