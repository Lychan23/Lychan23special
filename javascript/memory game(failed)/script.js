document.addEventListener("DOMContentLoaded", function() {
    const cards = ["A", "A", "B", "B", "C", "C", "D", "D", "E", "E", "F", "F", "G", "G", "H", "H"];
    let level = 1;
    let moves = 0;
    let timer = 0;
    let timerInterval;
    let flippedCards = [];
    let matchedCards = [];
  
    const grid = document.querySelector(".grid");
    const levelElement = document.getElementById("level");
    const movesElement = document.getElementById("moves");
    const timerElement = document.getElementById("timer");
  
    // Create the game grid
    function createGrid() {
      grid.innerHTML = "";
      for (let i = 0; i < cards.length; i++) {
        const card = document.createElement("div");
        card.classList.add("card");
        card.dataset.card = cards[i];
        card.addEventListener("click", flipCard);
        grid.appendChild(card);
      }
    }
  
    // Shuffle the cards
    function shuffleCards() {
      for (let i = cards.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [cards[i], cards[j]] = [cards[j], cards[i]];
      }
    }
  
    // Flip a card
    function flipCard() {
      if (flippedCards.length < 2 && !this.classList.contains("flipped") && !this.classList.contains("matched")) {
        this.classList.add("flipped");
        flippedCards.push(this);
        if (flippedCards.length === 2) {
          moves++;
          movesElement.textContent = moves;
          if (flippedCards[0].dataset.card === flippedCards[1].dataset.card) {
            flippedCards.forEach(card => card.classList.add("matched"));
            matchedCards.push(...flippedCards);
            checkGameEnd();
          } else {
            setTimeout(() => {
              flippedCards.forEach(card => card.classList.remove("flipped"));
            }, 1000);
          }
          flippedCards = [];
        }
      }
    }
  
    // Start the game
    function startGame() {
      shuffleCards();
      createGrid();
      levelElement.textContent = level;
      movesElement.textContent = moves;
      startTimer();
    }
  
    // Check if the game has ended
    function checkGameEnd() {
      if (matchedCards.length === cards.length) {
        clearInterval(timerInterval);
        setTimeout(() => {
          level++;
          moves = 0;
          timer = 0;
          flippedCards = [];
          matchedCards = [];
          startGame();
        }, 1000);
      }
    }
  
    // Timer logic
    function startTimer() {
      clearInterval(timerInterval);
      timerInterval = setInterval(() => {
        timer++;
        timerElement.textContent = timer;
      }, 1000);
    }
  
    // Initialize the game
    startGame();
  });
  