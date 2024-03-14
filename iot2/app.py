import cv2
import requests
import time
from flask import Flask, request, jsonify, render_template, Response

app = Flask(__name__)

# Global variable to store tracking status
tracking_status = ''

def scan_qr_code():
    qr_code_detector = cv2.QRCodeDetector()
    cap = cv2.VideoCapture(0)

    while True:
        _, frame = cap.read()
        data, _, _ = qr_code_detector.detectAndDecode(frame)
        
        if data:
            # Send scanned data to web server
            payload = {'status': data}
            response = requests.post(API_ENDPOINT, json=payload)
            if response.status_code == 200:
                print("Progress updated successfully:", data)
            else:
                print("Failed to update progress")
                print("Response content:", response.content)  # Log response content

        cv2.imshow("QR Code Scanner", frame)
        if cv2.waitKey(1) == ord("q"):
            break

    cap.release()
    cv2.destroyAllWindows()

# Endpoint to get the current tracking status
@app.route('/api/get_status', methods=['GET'])
def get_status():
    global tracking_status
    return jsonify({'status': tracking_status})

# Endpoint to update the tracking progress
@app.route('/api/update_progress', methods=['POST'])
def update_progress():
    global tracking_status
    data = request.json
    status = data.get('status')
    if status:
        # Update tracking progress based on received status
        tracking_status = status
        return jsonify({'message': 'Progress updated successfully'}), 200
    else:
        return jsonify({'error': 'Invalid request'}), 400

# Route to serve the HTML file
@app.route('/')
def index():
    return render_template('index.html')

# Route to serve QR scanner feed
@app.route('/video_feed')
def video_feed():
    # Replace this with the function that generates the video feed
    return Response(scan_qr_code(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(debug=True)
