// Array of fallback quotes with authors
const fallbackQuotes = [
    {
        quote: "The best way to predict the future is to invent it.",
        author: "Alan Kay"
    },
    {
        quote: "Your time is limited, don’t waste it living someone else’s life.",
        author: "Steve Jobs"
    },
    {
        quote: "The only limit to our realization of tomorrow is our doubts of today.",
        author: "Franklin D. Roosevelt"
    },
    {
        quote: "You miss 100% of the shots you don’t take.",
        author: "Wayne Gretzky"
    },
    {
        quote: "Whether you think you can or think you can’t, you’re right.",
        author: "Henry Ford"
    },
    {
        quote: "The secret of getting ahead is getting started.",
        author: "Mark Twain"
    },
    {
        quote: "Don’t watch the clock; do what it does. Keep going.",
        author: "Sam Levenson"
    },
    {
        quote: "Success is not the key to happiness. Happiness is the key to success.",
        author: "Albert Schweitzer"
    },
    {
        quote: "Success usually comes to those who are too busy to be looking for it.",
        author: "Henry David Thoreau"
    }
];

// Function to fetch a random quote from the API
async function fetchQuoteFromAPI() {
    try {
        const response = await fetch('https://dummyjson.com/quotes/random');
        if (!response.ok) {
            throw new Error('API request failed');
        }
        const data = await response.json();
        return {
            quote: data.quote,
            author: data.author
        };
    } catch (error) {
        console.error('Error fetching quote from API:', error);
        return null;  // Return null to indicate failure
    }
}

// Function to get a random quote from the fallback array
function getRandomQuoteFromFallback() {
    const randomIndex = Math.floor(Math.random() * fallbackQuotes.length);
    return fallbackQuotes[randomIndex];
}

// Function to display the quote and author
function displayQuote(quoteData) {
    const quoteElement = document.getElementById('quote');
    const authorElement = document.getElementById('author');
    quoteElement.querySelector('p').textContent = `"${quoteData.quote}"`;
    authorElement.textContent = quoteData.author;
}

// Event listener for the "Get New Quote" button
document.getElementById('new-quote').addEventListener('click', async () => {
    // Try to fetch a quote from the API
    const quoteFromAPI = await fetchQuoteFromAPI();
    
    // If the API fetch fails, use a fallback quote
    const quoteToDisplay = quoteFromAPI || getRandomQuoteFromFallback();
    displayQuote(quoteToDisplay);
});
