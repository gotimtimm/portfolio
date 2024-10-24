console.log("Portfolio website ready!");

function openOverlay(overlayId) {
  const overlay = document.getElementById(overlayId);
  const overlayContent = overlay.querySelector('.overlay-content');
  overlay.classList.add('active');
  overlayContent.classList.add('active');
}

function closeOverlay(overlayId) {
  const overlay = document.getElementById(overlayId);
  const overlayContent = overlay.querySelector('.overlay-content');
  overlayContent.classList.remove('active');
  overlay.classList.remove('active');
}

function filterProjects() {
  const searchInput = document.querySelector('.top-nav input').value.toLowerCase();
  const projectCards = document.querySelectorAll('.project-card');

  projectCards.forEach(card => {
    const title = card.querySelector('h3').textContent.toLowerCase();
    const description = card.querySelector('p').textContent.toLowerCase();
    
    if (title.includes(searchInput) || description.includes(searchInput)) {
      card.style.display = '';
    } else {
      card.style.display = 'none';
    }
  });
}

const searchInput = document.querySelector('.top-nav input');
searchInput.addEventListener('input', filterProjects);
