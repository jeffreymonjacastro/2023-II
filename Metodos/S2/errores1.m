clc

% Se crean dos variables para utilizar en las funciones
syms x y

% Errores absolutos de x e y respectivamente
er1 = 4;
er2 = 2;

% Función f
f = x*y/(x+y);


derf_y = diff(f, {y});

error = abs(derf_x)*er1 + abs(derf_y)*er2;

errorabsoluto = subs(error, {x,y}, {20,300}); 

double(errorabsoluto)