let tasks = [];

function renderTasks() {
    const taskList = document.getElementById("taskList");
    taskList.innerHTML = "";

    tasks.forEach((task, index) => {
        const taskItem = document.createElement("div");
        taskItem.className = "taskItem" + (task.completed ? " completed" : "");

        const checkbox = document.createElement("input");
        checkbox.type = "checkbox";
        checkbox.checked = task.completed;
        checkbox.addEventListener("change", () => toggleTaskCompleted(index));

        const taskText = document.createElement("span");
        taskText.innerText = task.text;

        const deleteButton = document.createElement("span");
        deleteButton.className = "deleteButton";
        deleteButton.innerText = "Delete";
        deleteButton.addEventListener("click", () => deleteTask(index));

        taskItem.appendChild(checkbox);
        taskItem.appendChild(taskText);
        taskItem.appendChild(deleteButton);

        taskList.appendChild(taskItem);
    });
}

function addTask() {
    const taskInput = document.getElementById("taskInput");
    const taskText = taskInput.value.trim();

    if (taskText !== "") {
        const newTask = {
            text: taskText,
            completed: false
        };

        tasks.push(newTask);
        taskInput.value = "";
        renderTasks();
    }
}

function toggleTaskCompleted(index) {
    tasks[index].completed = !tasks[index].completed;
    renderTasks();
}

function deleteTask(index) {
    tasks.splice(index, 1);
    renderTasks();
}

// Initial rendering
renderTasks();
