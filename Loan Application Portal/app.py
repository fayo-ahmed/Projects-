from flask import Flask, jsonify, render_template, request

app = Flask(__name__)

# In-memory database to store applications
applications = []
application_counter = 1  # To generate unique application numbers

# API to accept a loan application
@app.route('/api/accept', methods=['POST'])
def accept_application():
    global application_counter
    data = request.get_json()
    name = data.get('name')
    zipcode = data.get('zipcode')

    if not name or not zipcode:
        return jsonify({'error': 'Name and Zipcode are required'}), 400

    # Check if an application with the same name and zipcode already exists
    for app in applications:
        if app['name'] == name and app['zipcode'] == zipcode:
            return jsonify({'error': 'Application with this name and zipcode already exists', 'application_number': app['application_number']}), 400

    # Create a new application record
    application = {
        'application_number': application_counter,
        'name': name,
        'zipcode': zipcode,
        'status': 'received'
    }
    applications.append(application)
    application_counter += 1

    return jsonify({'message': 'Application accepted successfully', 'application_number': application['application_number']}), 201

# API to check the status of a loan application
@app.route('/api/status/<int:application_number>', methods=['GET'])
def check_status(application_number):
    for app in applications:
        if app['application_number'] == application_number:
            return jsonify({'status': app['status']}), 200
    return jsonify({'error': 'Application not found'}), 404

# API to change the status of a loan application
@app.route('/api/change_status', methods=['POST'])
def change_status():
    data = request.get_json()
    application_number = data.get('application_number')
    new_status = data.get('new_status')

    if not application_number or not new_status:
        return jsonify({'error': 'Application number and new status are required'}), 400

    for app in applications:
        if app['application_number'] == application_number:
            app['status'] = new_status
            return jsonify({'message': 'Status updated successfully'}), 200

    return jsonify({'error': 'Application not found'}), 404

# Route to render the index.html page
@app.route('/')
def index():
    return render_template('index.html')

# Optional API to retrieve all applications (for testing purposes)
@app.route('/api/applications', methods=['GET'])
def get_all_applications():
    return jsonify({'applications': applications}), 200

if __name__ == '__main__':
    app.run(debug=True, host="0.0.0.0")