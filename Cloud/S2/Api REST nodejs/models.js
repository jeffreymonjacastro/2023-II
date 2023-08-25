module.exports = (sequelize, DataType) => {

  const users = sequelize.define('users', {
    id: {
      type: DataType.INTEGER,
      primaryKey: true,
      autoIncrement: true
    },

    username: {
      type: DataType.STRING(50),
      allowNull: false,
      validate: {
        notEmpty: true
      }
    },

    password: {
      type: DataType.STRING(50),
      allowNull: false,
      validate: {
        notEmpty: true
      }
    },
  })

  return users;
}