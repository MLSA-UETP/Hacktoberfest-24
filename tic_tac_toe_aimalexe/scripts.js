const cells = document.querySelectorAll('[data-cell]');
const messageElement = document.getElementById('message');
const restartButton = document.getElementById('restartButton');
let currentPlayer = 'X';
let gameActive = true;
const winningCombinations = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
];

// Initialize the game
function startGame() {
    cells.forEach(cell => {
        cell.addEventListener('click', handleClick, { once: true });
    });
    setMessage(`Player ${currentPlayer}'s turn`);
}

// Handle click event on a cell
function handleClick(e) {
    const cell = e.target;
    if (!gameActive) return;

    cell.textContent = currentPlayer;
    if (checkWin(currentPlayer)) {
        setMessage(`Player ${currentPlayer} wins!`);
        endGame();
    } else if (isDraw()) {
        setMessage('It\'s a draw!');
        endGame();
    } else {
        switchPlayer();
    }
}

// Switch the current player
function switchPlayer() {
    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
    setMessage(`Player ${currentPlayer}'s turn`);
}

// Check for a win
function checkWin(player) {
    return winningCombinations.some(combination => {
        return combination.every(index => {
            return cells[index].textContent === player;
        });
    });
}

// Check for a draw
function isDraw() {
    return [...cells].every(cell => {
        return cell.textContent === 'X' || cell.textContent === 'O';
    });
}

// End the game
function endGame() {
    gameActive = false;
    cells.forEach(cell => {
        cell.removeEventListener('click', handleClick);
    });
}

// Restart the game
restartButton.addEventListener('click', () => {
    cells.forEach(cell => {
        cell.textContent = '';
        cell.addEventListener('click', handleClick, { once: true });
    });
    currentPlayer = 'X';
    gameActive = true;
    setMessage(`Player ${currentPlayer}'s turn`);
});

// Set the message
function setMessage(message) {
    messageElement.textContent = message;
}

// Start the game
startGame();
