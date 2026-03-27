# 01 - Brute Force Vector Search

## What is it

A minimal vector search engine built from scratch that performs **exact nearest neighbor (ENN)** search using a brute-force approach.

It stores embeddings (vectors) in memory and, for every query, performs a linear scan across all stored vectors to identify the most similar ones using distance metrics such as cosine similarity or L2 distance.

---

## Why I built this

This project was built to gain a deeper understanding of how vector databases work internally, rather than relying on existing solutions like FAISS or Pinecone.

It serves as a baseline system to:

* Understand exact nearest neighbor search before moving to approximate methods
* Explore performance trade-offs between accuracy and speed
* Build a strong foundation for advanced indexing techniques such as IVF and HNSW

---

## What I used

* **C++** — Core engine for efficient computation
* **Node.js** — Runtime environment
* **N-API** — Bridge between C++ and Node.js
* **Express.js** — API layer for interacting with the engine

---

## How to run locally

### Prerequisites

Ensure the following are installed on your system:

* **Node.js** (version 16 or higher)
* **npm**
* **Python** (required for node-gyp)
* **C++ build tools**

#### Windows

Install Visual Studio Build Tools with C++ support.

#### Linux

```bash
sudo apt install build-essential python3
```

#### macOS

```bash
xcode-select --install
```

---

### Install node-gyp

If node-gyp is not installed globally:

```bash
npm install -g node-gyp
```

---

### Clone the repository

```bash
git clone https://github.com/your-username/01_bruteforce_vector_search.git
cd 01_bruteforce_vector_search
```

---

### Install dependencies

```bash
npm install
```

---

### Build the native module

```bash
node-gyp configure
node-gyp build
```

Alternatively, if a build script is defined:

```bash
npm run build
```

---

### Start the server

```bash
node server/index.js
```

---

### Common issues

* **node-gyp errors**

  * Ensure Python is installed and available in PATH
  * Ensure a compatible C++ compiler is installed

* **Windows-specific issues**

  * Run the terminal with administrator privileges
  * Install additional build tools if required

---

After completing these steps, the API should be running locally and ready to accept vector insertion and search requests.
