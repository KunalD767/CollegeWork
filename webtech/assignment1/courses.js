document.addEventListener("DOMContentLoaded", function () {
    let xhr = new XMLHttpRequest();
    xhr.open("GET", "http://127.0.0.1:5500/webtech/assignment1/courses.xml", true);
    xhr.overrideMimeType("application/xml");

    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4) {
            console.log("Response Status:", xhr.status);
            if (xhr.status === 200) {
                let xmlDoc = xhr.responseXML;
                console.log("XML Loaded Successfully:", xmlDoc);

                let courses = xmlDoc.getElementsByTagName("course");
                let table = document.getElementById("courseTable");

                for (let i = 0; i < courses.length; i++) {
                    let row = table.insertRow();

                    row.insertCell(0).textContent = courses[i].getElementsByTagName("name")[0].textContent;
                    row.insertCell(1).textContent = courses[i].getElementsByTagName("code")[0].textContent;
                    row.insertCell(2).textContent = courses[i].getElementsByTagName("duration")[0].textContent;
                    row.insertCell(3).textContent = courses[i].getElementsByTagName("eligibility")[0].textContent;
                    row.insertCell(4).textContent = courses[i].getElementsByTagName("fees")[0].textContent;
                }
            } else {
                console.error("Failed to load XML:", xhr.status, xhr.statusText);
            }
        }
    };
    xhr.send();
});
