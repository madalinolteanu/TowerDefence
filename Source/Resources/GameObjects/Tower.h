class Tower {

public:
	Tower();
	Tower();
	~Tower();

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setZ(float z);
	float getZ();

	void setAngle(float angle);
	float getAngle();

	void setNGhiulea(int balls);
	int getNGhiulea();
	
	void setMesh(Mesh* mesh);
	Mesh* getMesh();

private:
	float x;
	float y;
	float z;
	float angle;
	int numGhiulele;
	Mesh* mesh;
	//vector(Ghiulea *);
	//mesh
	//
;
};
