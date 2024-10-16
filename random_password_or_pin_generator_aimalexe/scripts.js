// Character sets for password generation
const letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
const numbers = '0123456789';
const symbols = '@#$%^&*()-_=+[]{}<>?/!';

// Function to generate a random password or pin
function generatePasswordOrPin() {
    const type = document.getElementById('type').value;
    const minLength = parseInt(document.getElementById('min-length').value);
    const maxLength = parseInt(document.getElementById('max-length').value);
    const includeLetters = document.getElementById('include-letters').checked;
    const includeNumbers = document.getElementById('include-numbers').checked;
    const includeSymbols = document.getElementById('include-symbols').checked;

    let result = '';
    let characterSet = '';

    if (type === 'pin') {
        // For PIN, only use numbers
        characterSet = numbers;
    } else if (type === 'password') {
        // For Password, use selected character sets
        if (includeLetters) characterSet += letters;
        if (includeNumbers) characterSet += numbers;
        if (includeSymbols) characterSet += symbols;
        
        // Ensure at least one option is selected
        if (characterSet === '') {
            alert('Please select at least one character type for the password.');
            return;
        }
    }

    // Generate a random length within the range specified
    const length = Math.floor(Math.random() * (maxLength - minLength + 1)) + minLength;

    // Generate the password or pin
    for (let i = 0; i < length; i++) {
        const randomIndex = Math.floor(Math.random() * characterSet.length);
        result += characterSet[randomIndex];
    }

    // Display the result
    document.getElementById('result').value = result;
}

// Show/Hide password options based on user selection
document.getElementById('type').addEventListener('change', function() {
    const passwordOptions = document.getElementById('password-options');
    if (this.value === 'password') {
        passwordOptions.style.display = 'block';
    } else {
        passwordOptions.style.display = 'none';
    }
});

// Event listener for the generate button
document.getElementById('generate-btn').addEventListener('click', generatePasswordOrPin);
