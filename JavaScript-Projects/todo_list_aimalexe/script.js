// Select elements
const todoInput = document.getElementById('todo-input');
const addBtn = document.getElementById('add-btn');
const todoList = document.getElementById('todo-list');

// Load todos from localStorage when the page loads
document.addEventListener('DOMContentLoaded', loadTodos);

// Add a new todo
addBtn.addEventListener('click', () => {
    const todoText = todoInput.value.trim();
    if (todoText) {
        const todoItem = {
            id: Date.now(),
            text: todoText
        };
        addTodoToList(todoItem);
        saveTodoToStorage(todoItem);
        todoInput.value = '';
    }
});

// Handle edit and delete actions
todoList.addEventListener('click', (e) => {
    if (e.target.classList.contains('delete')) {
        const li = e.target.closest('li');
        removeTodoFromList(li);
        removeTodoFromStorage(li.dataset.id);
    } else if (e.target.classList.contains('edit')) {
        const li = e.target.closest('li');
        const newText = prompt('Edit your task:', li.querySelector('span').textContent);
        if (newText !== null && newText.trim() !== '') {
            updateTodoInList(li, newText.trim());
            updateTodoInStorage(li.dataset.id, newText.trim());
        }
    }
});

// Functions
function addTodoToList(todoItem) {
    const li = document.createElement('li');
    li.dataset.id = todoItem.id;
    li.innerHTML = `
        <span>${todoItem.text}</span>
        <div class="actions">
            <i class="fas fa-edit edit"></i>
            <i class="fas fa-trash delete"></i>
        </div>
    `;
    todoList.appendChild(li);
}

function removeTodoFromList(li) {
    todoList.removeChild(li);
}

function updateTodoInList(li, newText) {
    li.querySelector('span').textContent = newText;
}

function saveTodoToStorage(todoItem) {
    const todos = getTodosFromStorage();
    todos.push(todoItem);
    localStorage.setItem('todos', JSON.stringify(todos));
}

function removeTodoFromStorage(id) {
    let todos = getTodosFromStorage();
    todos = todos.filter(todo => todo.id !== Number(id));
    localStorage.setItem('todos', JSON.stringify(todos));
}

function updateTodoInStorage(id, newText) {
    const todos = getTodosFromStorage();
    todos.forEach(todo => {
        if (todo.id === Number(id)) {
            todo.text = newText;
        }
    });
    localStorage.setItem('todos', JSON.stringify(todos));
}

function loadTodos() {
    const todos = getTodosFromStorage();
    todos.forEach(todo => addTodoToList(todo));
}

function getTodosFromStorage() {
    return localStorage.getItem('todos') ? JSON.parse(localStorage.getItem('todos')) : [];
}
