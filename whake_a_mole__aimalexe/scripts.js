let score = 0;
let currentTime = 30;
let timerId = null;
let moleTimer = null;
let hitPosition = null;

const holes = document.querySelectorAll('.hole');
const scoreElement = document.getElementById('score');
const timeLeftElement = document.getElementById('time-left');
const startButton = document.getElementById('start-button');

// Function to randomly select a hole for the mole to appear
function randomHole() {
    holes.forEach(hole => {
        hole.classList.remove('active');
    });

    const randomHole = holes[Math.floor(Math.random() * holes.length)];
    randomHole.classList.add('active');
    hitPosition = randomHole.id;
}

// Function to count down the time
function countdown() {
    currentTime--;
    timeLeftElement.textContent = currentTime;

    if (currentTime === 0) {
        clearInterval(timerId);
        clearInterval(moleTimer);
        alert('Game Over! Your final score is ' + score);
        resetGame();
    }
}

// Function to start the game
function startGame() {
    score = 0;
    currentTime = 30;
    scoreElement.textContent = score;
    timeLeftElement.textContent = currentTime;

    timerId = setInterval(countdown, 1000);
    moleTimer = setInterval(randomHole, 1000);
}

// Function to reset the game after it ends
function resetGame() {
    clearInterval(timerId);
    clearInterval(moleTimer);
    holes.forEach(hole => hole.classList.remove('active'));
    hitPosition = null;
}

// Event listener for hitting the mole
holes.forEach(hole => {
    hole.addEventListener('click', () => {
        if (hole.id === hitPosition) {
            score++;
            scoreElement.textContent = score;
            hitPosition = null;
        }
    });
});

// Event listener for starting the game
startButton.addEventListener('click', () => {
    if (!timerId && !moleTimer) {
        startGame();
    }
});
