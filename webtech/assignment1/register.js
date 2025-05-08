document.addEventListener("DOMContentLoaded", function() {
    console.log("JS loaded - Custom form validation started.");

    const form = document.getElementById("enrollmentForm");
    const nameInput = document.getElementById("name");
    const emailInput = document.getElementById("email");
    const mobileInput = document.getElementById("mobile");
    const courseSelect = document.getElementById("course");
    const messageEl = document.getElementById("message");

    form.addEventListener("submit", function(event) {
        event.preventDefault(); 

        const nameValue = nameInput.value.trim();
        const emailValue = emailInput.value.trim();
        const mobileValue = mobileInput.value.trim();
        const courseValue = courseSelect.value;

        if (nameValue === "" || emailValue === "" || mobileValue === "" || courseValue === "") {
            showMessage("⚠️ Please fill in all fields.", "error");
            return;
        }

        if (!isValidEmail(emailValue)) {
            showMessage("❌ Please enter a valid email address.", "error");
            return;
        }

        if (!isValidMobile(mobileValue)) {
            showMessage("❌ Please enter a 10-digit mobile number.", "error");
            return;
        }

        showMessage("✅ Thank you for enrolling in our course!", "success");
        
        form.reset();
    });

    function isValidEmail(email) {
        const pattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/; 
        return pattern.test(email);
    }

    function isValidMobile(number) {
        return /^[0-9]{10}$/.test(number);
    }

    function showMessage(msg, type) {
        messageEl.textContent = msg;
        messageEl.style.color = (type === "success") ? "green" : "red";
        messageEl.style.fontWeight = "bold";
        messageEl.style.marginTop = "10px";
    }
});