document.addEventListener("DOMContentLoaded", function() {
    document.getElementById("checkBtn").addEventListener("click", function() {
        let num = document.getElementById("numberInput").value;
        let resultText = "";

        if (num === "") {
            resultText = "Please enter a number!";
        } else {
            num = parseInt(num);
            resultText = (num % 2 === 0) ? "✅ The number is EVEN" : "❌ The number is ODD";
        }

        document.getElementById("result").innerHTML = resultText;
    });
});