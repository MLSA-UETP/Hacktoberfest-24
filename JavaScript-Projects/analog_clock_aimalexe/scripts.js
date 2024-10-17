function updateClock() {
    const now = new Date();

    // Get current time
    const seconds = now.getSeconds();
    const minutes = now.getMinutes();
    const hours = now.getHours();

    // Rotate the hands
    const secondHand = document.getElementById('second');
    const minuteHand = document.getElementById('minute');
    const hourHand = document.getElementById('hour');

    const secondDegree = ((seconds / 60) * 360) + 90;
    const minuteDegree = ((minutes / 60) * 360) + ((seconds / 60) * 6) + 90;
    const hourDegree = ((hours / 12) * 360) + ((minutes / 60) * 30) + 90;

    secondHand.style.transform = `translateX(-50%) rotate(${secondDegree}deg)`;
    minuteHand.style.transform = `translateX(-50%) rotate(${minuteDegree}deg)`;
    hourHand.style.transform = `translateX(-50%) rotate(${hourDegree}deg)`;

    // Update the date
    const options = { weekday: 'long', day: '2-digit', month: 'long', year: 'numeric' };
    const dateString = now.toLocaleDateString('en-US', options);
    document.getElementById('date').textContent = dateString;
}

// Call updateClock every second
setInterval(updateClock, 1000);

// Initial call to set the time immediately
updateClock();
