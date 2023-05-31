const quiz = [
    {
        question: "What is the capital of France?",
        choices: ["Paris", "London", "Berlin", "Madrid"],
        correctAnswer: 0
    },
    {
        question: "Which planet is known as the Red Planet?",
        choices: ["Mars", "Venus", "Jupiter", "Saturn"],
        correctAnswer: 0
    },
    {
        question: "What is the largest ocean in the world?",
        choices: ["Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"],
        correctAnswer: 0
    }
];

let currentQuestion = 0;
let score = 0;
let timer;

function startQuiz() {
    renderQuestion();
    startTimer(60);
}

function renderQuestion() {
    const question = document.getElementById("question");
    const choices = document.getElementById("choices");
    const nextButton = document.getElementById("nextButton");

    question.innerText = quiz[currentQuestion].question;
    choices.innerHTML = "";

    quiz[currentQuestion].choices.forEach((choice, index) => {
        const radio = document.createElement("input");
        radio.type = "radio";
        radio.name = "answer";
        radio.value = index;

        const label = document.createElement("label");
        label.innerText = choice;

        choices.appendChild(radio);
        choices.appendChild(label);
        choices.appendChild(document.createElement("br"));
    });

    nextButton.disabled = true;
}

function checkAnswer() {
    const nextButton = document.getElementById("nextButton");
    const choices = document.getElementsByName("answer");
    let selectedChoice = -1;

    choices.forEach((choice) => {
        if (choice.checked) {
            selectedChoice = parseInt(choice.value);
        }
    });

    nextButton.disabled = selectedChoice === -1;
}

function nextQuestion() {
    const choices = document.getElementsByName("answer");
    let selectedChoice = -1;

    choices.forEach((choice) => {
        if (choice.checked) {
            selectedChoice = parseInt(choice.value);
            choice.checked = false;
        }
    });

    if (selectedChoice === quiz[currentQuestion].correctAnswer) {
        score++;
    }

    currentQuestion++;

    if (currentQuestion < quiz.length) {
        renderQuestion();
    } else {
        endQuiz();
    }
}

function endQuiz() {
    clearInterval(timer);
    document.getElementById("quiz").innerHTML = "";
    document.getElementById("score").innerText = `Score: ${score}/${quiz.length}`;
}

function startTimer(duration) {
    let time = duration;
    timer = setInterval(() => {
        const timerDisplay = document.getElementById("timer");
        timerDisplay.innerText = `Time left: ${time} seconds`;

        if (time <= 0) {
            clearInterval(timer);
            endQuiz();
            return;
        }

        time--;
    }, 1000);
}

// Start the quiz when the page loads
window.onload = startQuiz;
