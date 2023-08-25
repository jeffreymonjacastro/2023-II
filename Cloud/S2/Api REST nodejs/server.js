const express = require('express'); // Fast, unopinionated, minimalist web framework for node.
const morgan = require('morgan'); // Para ver las peticiones que se hacen al servidor en consola
const db = require('./db.js') // Importar la base de datos

const app = express(); // Iniciar la app


//settings
app.set('port', process.env.PORT || 3000) // Definir el puerto
app.set('json spaces', 2); // Para que los jsons se vean bonitos

//middlewares
app.use(morgan('dev')); // Dev logging (combined, common, dev, short, tiny)
app.use(express.json()); // Para leer jsons
app.use(express.urlencoded({extended: false})); // Para leer formularios
app.use((req, res, next) => {
  req.db = db;
  next();
});

// Routes
// Importar las rutas desde la carpeta routes
app.use(require('./routes/users'));


//starting the server
app.listen(app.get('port'), () => {
  console.log(`Server is running on port ${app.get('port')}`);
})
