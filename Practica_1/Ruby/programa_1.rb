class Punto

  def initialize(x, y)
    @x = x
    @y = y
  end

  def x=(x)
    @x = x
  end

  def x
    @x
  end

  def y=(y)
    @y = y
  end

end

a = Punto.new(0, 0)

print "Ingrese la coordenada x: "
a.x = gets
print "Ingrese la coordenada y: "
a.y = gets

puts a

a.methods
