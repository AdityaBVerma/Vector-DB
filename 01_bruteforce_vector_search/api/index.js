const express = require('express');
const app = express();

const vectorEngine = require('../build/Release/vector_engine')

app.use(express.json());

app.post('/insert', (req, res) => {
    const { embedding, text } = req.body;

    if (!embedding || !text) {
        return res.status(400).json({ error: "Missing embedding or text" });
    }

    vectorEngine.insert(embedding, text);

    res.json({ message: "Inserted successfully" });
});

app.post('/search', (req, res) => {
    const { query } = req.body;

    if (!query) {
        return res.status(400).json({ error: "Missing query" });
    }

    const results = vectorEngine.search(query);

    res.json({ results });
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});