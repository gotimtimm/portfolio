// script.js

// Placeholder for future interactivity
console.log("Portfolio website ready!");

// Function to open the overlay with smooth transition
function openOverlay(overlayId) {
  const overlay = document.getElementById(overlayId);
  const overlayContent = overlay.querySelector('.overlay-content');
  overlay.classList.add('active');
  overlayContent.classList.add('active');
}

// Function to close the overlay with smooth transition
function closeOverlay(overlayId) {
  const overlay = document.getElementById(overlayId);
  const overlayContent = overlay.querySelector('.overlay-content');
  overlayContent.classList.remove('active');
  overlay.classList.remove('active');
}

