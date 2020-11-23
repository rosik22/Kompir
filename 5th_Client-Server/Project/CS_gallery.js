var slideIndex = 1;
var current = 0;
var slides = document.getElementsByClassName("mySlides");
showSlides(slideIndex);

function plusSlides(n) {
    showSlides(slideIndex += n);
    current = slideIndex;
}

function currentSlide(n) {
    showSlides(slideIndex = n);
    current = n;
}

function showSlides(n) {
    var i;
    var dots = document.getElementsByClassName("demo");
    if (n > slides.length) { slideIndex = 1 }
    if (n < 1) { slideIndex = slides.length }
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active", "");
    }
    slides[slideIndex - 1].style.display = "block";
    dots[slideIndex - 1].className += " active";
}

$(document).ready(function() {
    setInterval(function() {
        current = (current < slides.length - 1) ? current + 1 : 0;
        currentSlide(current);
    }, 3000);
});