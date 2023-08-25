const { Router } = require('express');
const router = Router();

// GET users
router.get('/users', async (req, res) => {
  try {
    const users = await req.db.models.users.findAll();
    res.json(users);
    
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

// POST users
router.post('/users', async (req, res) => {
  try {
    const user = await req.db.models.users.create(req.body);
    res.json({message: `User ${user.username} created successfully`});

  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

// GET user by id
router.get('/users/:id', async (req, res) => {
  try {
    const user = await req.db.models.users.findByPk(req.params.id);
    res.json(user);

  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

// PUT user
router.put('/users/:id', async (req, res) => {
  try {
    const user = await req.db.models.users.findByPk(req.params.id);
    await user.update(req.body);
    res.json({message: `User ${user.username} updated successfully`});

  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

// DELETE user
router.delete('/users/:id', async (req, res) => {
  try {
    const user = await req.db.models.users.findByPk(req.params.id);
    await user.destroy();
    res.json({message: `User ${user.username} deleted successfully`});
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

module.exports = router;