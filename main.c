#include "mlx.h"

// int deal_key(int key, void *param){
//     return (0);
// }

int main(){

    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 500,"hello world");
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
   // mlx_key_hook(win_ptr, deal_key, (void *) 0);
    mlx_loop(mlx_ptr);
}