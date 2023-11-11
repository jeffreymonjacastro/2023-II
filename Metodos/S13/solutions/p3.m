format long
a = 0;
b = 2;
h = 0.04;

syms x y

f = @(x,y)(-y + 10*sin(3*x));
y0 = 0;


[z] = RK4(f,a,b,y0,h)

xx = (z(:,1))';
yy = (z(:,2))';

y1_aprox = yy(1/h + 1)



S=splinenatural(xx,yy)
i = 0.88/h + 1;

S(i,:)

a = S(i,1)
b = S(i,2)
c = S(i,3)
d = S(i,4)

x1 = xx(i)

g  = matlabFunction( a*(x-x1)*(x-x1)*(x-x1) + b*(x-x1)*(x-x1) + c*(x-x1) + d )

ypi_aprox = g(sqrt(pi/4))


syms y(x) x
y(x) = dsolve(diff(y,x) == -y + 10*sin(3*x) , y(0) == 0)
y = matlabFunction(y(x));
ypi_exac = y(sqrt(pi/4));

err_aproxpi = abs(ypi_exac - ypi_aprox)/abs(ypi_exac)

function [z] = RK4(f,a,b,y0,h)
    n = (b-a)/h;
    t = (a:h:b)';
    z = [];
    for i = 1:(n+1)
        k1 = f(t(i),y0);
        k2 = f(t(i)+h/2,y0 + k1*(h/2));
        k3 = f(t(i)+h/2,y0 + k2*(h/2));
        k4 = f(t(i) + h , y0 + k3*h);
        y1 = y0 + (k1 + 2*k2 + 2*k3 +k4)*(h/6);
        z = [z;t(i) y0 k1 k2 k3 k4 y1];
        y0 = y1;    
    end
end


function S=splinenatural(X,Y)
N=length(X)-1;
H=diff(X);
E=diff(Y)./H;
diagprinc=2*(H(1:N-1)+H(2:N));
diagsupinf=H(2:N-1);
g0=0; gn=0;
A=diag(diagprinc)+diag(diagsupinf,1)+diag(diagsupinf,-1);
b=6*diff(E');
g=A\b;
g=[g0 g' gn ];
for i=1:N
    S(i,1)=(g(i+1)-g(i))/(6*H(i));
    S(i,2)=g(i)/2;
    S(i,3)=E(i)-H(i)*(g(i+1)+2*g(i))/6;
    S(i,4)=Y(i);
    xx=linspace(X(i),X(i+1),100);
    yy=S(i,1)*(xx-X(i)).^3+S(i,2)*(xx-X(i)).^2+S(i,3)*(xx-X(i))+S(i,4);
    plot(xx,yy)
    hold on
end
grid on
hold off
end