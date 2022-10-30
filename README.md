# Cub3D

This Repositorie contains my solution to the project `cub3d` of 42 (Paris).

[![cmaginot's 42 stats](https://badge42.vercel.app/api/v2/cl1s5sord008509mlo7xr33zy/stats?cursusId=21&coalitionId=45)](https://github.com/JaeSeoKim/badge42)

[![cmaginot's 42 cub3d Score](https://badge42.vercel.app/api/v2/cl1s5sord008509mlo7xr33zy/project/2580204)](https://github.com/JaeSeoKim/badge42)

## Description

This project aims to make a game with the raycasting methode.

## Using Cub3D

### Cloning

```shell
git clone --recurse-submodules https://github.com/Freya-Tenebrae/Cub3D.git
```

### Cub3D

On Cub3dD there is no door, no entities, no pickup, no end, no action possible (exept movement) and textures are defined by wall orientation

#### Compilation

```shell
make
```

#### launch

```shell
./cub3d maps/test.cub
```

### Witch's_Escape

Witch's escape is an advenced version of cub3D, textures depend on map and some texture are animated.
Movement depend on time and not on processor speed.
Exit, pickup and "ennemies" are present and you can interact with them.
There is a system of multiple maps, life, spell slot that regen with time and an ath.

#### Compilation

```shell
make bonus
```

#### launch

```shell
./Witch\'s_Escape
```

### keys

- esc : exit
- w : move forward
- a : move left
- s : move backward
- d : move right
- ↑ : look up
- ← : look left
- ↓ : look down
- → : look right
- enter or middle click : start or resume the game (bonus only)
- e or right click : interact (bonus only)
- a or left click : transform a witch in a cat for a limited time (only one witch can be transformed at a time) (bonus only)

## Credits

>Tileset	: [Rogue Fantasy Castle](https://szadiart.itch.io/rogue-fantasy-castle)  by szadi art

>Magic wall : [32x32 2D Portal Asset Pack](https://actuallykron.itch.io/32x32-2d-portal-asset-pack) by actuallykron

>Cat		: [Catset](https://seethingswarm.itch.io/catset)  by seethingswarm

>Witches	: [Witches pack](https://9e0.itch.io/witches-pack)  by 9e0

>Pickup	: [32x32 in game items asset pack](https://beyonderboy.itch.io/32x32-in-game-items-asset-pack)  by beyonderboy

>Pickup (cristal) : [Kyrise's Free 16x16 RPG Icon Pack](https://kyrise.itch.io/kyrises-free-16x16-rpg-icon-pack) by Kyrise
