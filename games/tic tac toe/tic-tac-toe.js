// Set up game state
let currentPlayer = "X";
let gameEnd = false;
let board = [
  ["", "", ""],
  ["", "", ""],
  ["", "", ""],
];

// Create board elements
const boardContainer = document.querySelector(".board");
for (let row = 0; row < 3; row++) {
  for (let col = 0; col < 3; col++) {
    const cell = document.createElement("div");
    cell.classList.add("cell");
    cell.addEventListener("click", () => makeMove(row, col));
    boardContainer.appendChild(cell);
  }
}

// Make a move
function makeMove(row, col) {
  if (!gameEnd && board[row][col] === "") {
    board[row][col] = currentPlayer;
    const cell = boardContainer.children[row * 3 + col];
    cell.textContent = currentPlayer;
    cell.classList.add("marked");

    if (checkWin()) {
      announceWinner();
      gameEnd = true;
    } else if (checkTie()) {
      announceTie();
      gameEnd = true;
    } else {
      currentPlayer = currentPlayer === "X" ? "O" : "X";
    }
  }
}

// Check for a win
function checkWin() {
  for (let i = 0; i < 3; i++) {
    if (
      board[i][0] === currentPlayer &&
      board[i][1] === currentPlayer &&
      board[i][2] === currentPlayer
    ) {
      return true;
    }

    if (
      board[0][i] === currentPlayer &&
      board[1][i] === currentPlayer &&
      board[2][i] === currentPlayer
    ) {
      return true;
    }
  }

  if (
    board[0][0] === currentPlayer &&
    board[1][1] === currentPlayer &&
    board[2][2] === currentPlayer
  ) {
    return true;
  }

  if (
    board[0][2] === currentPlayer &&
    board[1][1] === currentPlayer &&
    board[2][0] === currentPlayer
  ) {
    return true;
  }

  return false;
}

// Check for a tie
function checkTie() {
  for (let row = 0; row < 3; row++) {
    for (let col = 0; col < 3; col++) {
      if (board[row][col] === "") {
        return false;
      }
    }
  }

  return true;
}

// Announce the winner
function announceWinner() {
  setTimeout(() => {
    alert(`Player ${currentPlayer} wins!`);
  }, 100);
}

// Announce a tie
function announceTie() {
  setTimeout(() => {
    alert("It's a tie!");
  }, 100);
}
