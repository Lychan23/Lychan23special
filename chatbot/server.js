const express = require('express');
const app = express();
const server = require('http').Server(app);
const io = require('socket.io')(server);

const PORT = 3000;

app.use(express.static('public'));

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

let connectedUsers = {};

io.on('connection', (socket) => {
  socket.on('new-user', (username) => {
    connectedUsers[socket.id] = username;
    socket.broadcast.emit('user-connected', username);
  });

  socket.on('send-message', (message) => {
    socket.broadcast.emit('chat-message', {
      username: connectedUsers[socket.id],
      message: message,
    });
  });

  socket.on('disconnect', () => {
    socket.broadcast.emit('user-disconnected', connectedUsers[socket.id]);
    delete connectedUsers[socket.id];
  });
});

server.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
