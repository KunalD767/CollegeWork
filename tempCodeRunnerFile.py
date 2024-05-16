import chatbot.app as app
import chatterbot
import chatterbot.trainers

app = Flask(__name__)

chatbot = ChatBot('MyBot')
trainer = ChatterBotCorpusTrainer(chatbot)
trainer.train('chatterbot.corpus.english') 

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/get_response", methods=["POST"])
def get_response():
    user_message = request.form["user_message"]
    response = chatbot.get_response(user_message)
    return str(response)

if __name__ == "__main__":
    app.run(debug=True)
