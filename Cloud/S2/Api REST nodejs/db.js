const Sequelize = require('sequelize'); // ORM para bases de datos relacionales

const config = {
  database: 'users',
  username: '',
  password: '',
  params: {
    dialect: 'sqlite',
    storage: 'users-db.sqlite',
    define: {
      underscored: true
    },
  }
};

const sequelize = new Sequelize(
  config.database,
  config.username,
  config.password,
  config.params
);

db = {
  sequelize,
  Sequelize,
  models: {}
};

const UserModel = require('./models');
const User = UserModel(sequelize, Sequelize);

db.models.users = User;

sequelize.sync()


module.exports = db;
