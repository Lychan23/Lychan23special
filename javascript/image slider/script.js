const slider = document.querySelector('.slider');
const slides = slider.getElementsByTagName('img');
let currentSlide = 0;
let slideInterval;

function startSlider() {
    slideInterval = setInterval(nextSlide, 3000); // Change slide every 3 seconds
}

function nextSlide() {
    goToSlide(currentSlide + 1);
}

function prevSlide() {
    goToSlide(currentSlide - 1);
}

function goToSlide(n) {
    slides[currentSlide].classList.remove('active');
    currentSlide = (n + slides.length) % slides.length;
    slides[currentSlide].classList.add('active');
}

slider.addEventListener('mouseenter', () => {
    clearInterval(slideInterval);
});

slider.addEventListener('mouseleave', () => {
    startSlider();
});

startSlider();
