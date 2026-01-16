import requests

GEMINI_API_KEY = "YOUR_GEMINI_API_KEY"

def ask_gemini(text):
    url = f"https://generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent?key={GEMINI_API_KEY}"

    payload = {
        "contents": [{
            "parts": [{
                "text": f"""
                    You are a robot controller.
                    Convert the user sentence into ONE command from:
                    FORWARD, BACKWARD, LEFT, RIGHT, STOP.

                    User sentence: {text}

                    Only output the command.
                """
            }]
        }]
    }

    response = requests.post(url, json=payload)
    data = response.json()

    return data["candidates"][0]["content"]["parts"][0]["text"].strip()
