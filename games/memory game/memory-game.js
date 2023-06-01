// Set up card data
const cards = [
    { id: 1, value: "A" },
    { id: 2, value: "A" },
    { id: 3, value: "B" },
    { id: 4, value: "B" },
    { id: 5, value: "C" },
    { id: 6, value: "C" },
    { id: 7, value: "D" },
    { id: 8, value: "D" },
    { id: 9, value: "E" },
    { id: 10, value: "E" },
    { id: 11, value: "F" },
    { id: 12, value: "F" },
    { id: 13, value: "G" },
    { id: 14, value: "G" },
    { id: 15, value: "H" },
    { id: 16, value: "H" },
  ];
  
  // Shuffle the cards
  const shuffledCards = shuffle(cards);
  
  // Set up game state
  let flippedCards = [];
  let matchedCards = [];
  
  // Create card elements
  const memoryGame = document.querySelector(".memory-game");
  shuffledCards.forEach((card) => {
    const cardElement = document.createElement("div");
    cardElement.classList.add("card");
    cardElement.dataset.id = card.id;
    cardElement.textContent = card.value;
    cardElement.addEventListener("click", flipCard);
    memoryGame.appendChild(cardElement);
  });
  
  // Flip a card
  function flipCard() {
    if (flippedCards.length < 2 && !flippedCards.includes(this) && !matchedCards.includes(this)) {
      this.classList.add("flipped");
      flippedCards.push(this);
  
      if (flippedCards.length === 2) {
        setTimeout(checkMatch, 500);
      }
    }
  }
  
  // Check if the flipped cards match
  function checkMatch() {
    const card1 = flippedCards[0];
    const card2 = flippedCards[1];
  
    if (card1.dataset.id === card2.dataset.id) {
      matchedCards.push(card1, card2);
      checkWin();
    } else {
      card1.classList.remove("flipped");
      card2.classList.remove("flipped");
    }
  
    flippedCards = [];
  }
  
  // Check if the player has won the game
  function checkWin() {
    if (matchedCards.length === shuffledCards.length) {
      setTimeout(() => {
        alert("Congratulations! You've won the game!");
      }, 500);
    }
  }
  
  // Shuffle an array using the Fisher-Yates algorithm
  function shuffle(array) {
    const newArray = array.slice();
    for (let i = newArray.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));
      [newArray[i], newArray[j]] = [newArray[j], newArray[i]];
    }
    return newArray;
  }
  