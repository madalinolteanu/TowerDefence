class Enemy {

public:
	Enemy();
	~Enemy();

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setZ(float z);
	float getZ();

	void setAngle(float angle);
	float getAngle();

	void setNumLifes(int balls);
	int getNumLifes();

	void setMesh(Mesh* mesh);
	Mesh* getMesh();


private:
	float x;
	float y;
	float z;
	float angle;
	int numLifes;
	Mesh* mesh;

	//vector(Ghiulea *);
	//mesh
};
