<h1 align="center">
42-cub3d 125/100
</h1>
<div align="center">
  <img src="./.RD_img/cub3dm.png" alt="badge-so_long">
</div>

# Build

```
git clone https://github.com/42Paris/minilibx-linux.git
```
```
|
|- minilibx-linux/
|- src/
|- headers/
|- ...
|- Makefile
```

# Mandatory

## Cmd

 - **Left and right arrow keys** allow you to look left and right in the maze.
 - **The W, A, S, D keys** allow you to move.

## Run

```
make && ./cub3D maps/map.cub
```

<div align="center">
  <img src="./.RD_img/mandatory.gif" alt="gif_mandatory">
</div>

# Bonus

## Cmd

 - **Left and right arrow keys** allow you to look left and right in the maze.
 - **The W, A, S, D keys** allow you to move.
 - **E key** opens doors.
 - **Q key and right click** shoot.
 - **Space key** lights a torch.
 - **Ctrl key** disable the "fog".
 - You can use the mouse to look left and right.

## Run

```
make bonus && ./cub3D_bonus	 maps/map_bonus.cub
```

<div align="center">
  <img src="./.RD_img/bonus.gif" alt="gif_bonus">
</div>
