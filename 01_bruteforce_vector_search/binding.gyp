{
  "targets": [
    {
      "target_name": "vector_engine",
      "sources": ["binding.cpp", "vector_engine.cpp"],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "defines": [
        "NODE_ADDON_API_DISABLE_CPP_EXCEPTIONS"
      ],
      "cflags_cc": ["-std=c++17"]
    }
  ]
}