// Array to store application data locally (for testing purposes)
const applications = [];

// Function to submit a loan application and send it to the server
function submitApplication() {
    const applicantName = document.getElementById('applicantName').value;
    const zipcode = document.getElementById('zipcode').value;

    // Create a JSON object with application data
    const applicationData = {
        name: applicantName,
        zipcode: zipcode
    };

    // Send the application data to the server via POST request
    fetch('/api/accept', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(applicationData)
    })
        .then(response => {
            if (!response.ok) {
                return response.json().then(errorData => {
                    throw new Error(errorData.error || 'Failed to submit application');
                });
            }
            return response.json();
        })
        .then(data => {
            // Display a confirmation message with the application number
            alert(`Application submitted successfully! Your application number is: ${data.application_number}`);

            // Add the new application data to the applications array (for testing purposes)
            applications.push({ ...applicationData, application_number: data.application_number });
            console.log(applications);
        })
        .catch(error => {
            alert(error.message); // Display the error message
            console.error('Error submitting application:', error);
        });
}

// Function to check the status of an application
function checkStatus() {
    const appNumber = document.getElementById('appNumber').value;

    // Fetch the status of the application from the server
    fetch(`/api/status/${appNumber}`)
        .then(response => {
            if (!response.ok) {
                throw new Error('Application not found');
            }
            return response.json();
        })
        .then(data => {
            // Display the application status
            document.getElementById('statusOutput').textContent = `Status: ${data.status}`;
        })
        .catch(error => {
            document.getElementById('statusOutput').textContent = `Error: ${error.message}`;
        });
}

// Function to change the status of an application
function changeStatus() {
    const appNumber = document.getElementById('changeAppNumber').value;
    const newStatus = document.getElementById('newStatus').value;

    // Create a JSON object with the application number and new status
    const statusUpdate = {
        application_number: parseInt(appNumber),
        new_status: newStatus
    };

    // Send the status update to the server via POST request
    fetch('/api/change_status', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(statusUpdate)
    })
        .then(response => {
            if (!response.ok) {
                throw new Error('Failed to update status');
            }
            return response.json();
        })
        .then(data => {
            document.getElementById('changeStatusOutput').textContent = data.message;
        })
        .catch(error => {
            document.getElementById('changeStatusOutput').textContent = `Error: ${error.message}`;
        });
}

// Function to display all submitted applications (fetched from the server)
function showAllApplications() {
    fetch('/api/applications')
        .then(response => response.json())
        .then(data => {
            const appList = document.getElementById('applicationList');
            appList.innerHTML = ''; // Clear the existing list

            data.applications.forEach(app => {
                const appElement = document.createElement('div');
                appElement.innerHTML = `
                    <h3>Application #${app.application_number}</h3>
                    <p>Name: ${app.name}</p>
                    <p>Zipcode: ${app.zipcode}</p>
                    <p>Status: ${app.status}</p>
                `;
                appList.appendChild(appElement);
            });
        })
        .catch(error => {
            console.error('Error fetching applications:', error);
        });
}