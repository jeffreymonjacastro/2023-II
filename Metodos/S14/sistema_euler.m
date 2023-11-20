function z = sistema_euler(Dx,Dy,x0,y0,ti,tf,h)
t_val = [ti:h:tf]';
x_val = zeros(size(t_val));
y_val = zeros(size(t_val));
x_val(1)=x0;
y_val(1)=y0;

indice_tope = length(t_val)-1;
for i = 1:indice_tope
    ti = t_val(i);
    xi=x_val(i);
    yi=y_val(i);

    %Dx y Dy tienen la forma f(t,x,y)
    k1x=Dx(ti,xi,yi);
    k1y=Dy(ti,xi,yi);

    x_val(i+1) = xi+h*k1x;
    y_val(i+1) = yi+h*k1y;

end
z =[x_val(end) y_val(end)]
end

