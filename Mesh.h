#pragma once

#include "DX12Helper.h"
#include <wrl/client.h>

#include "Vertex.h"


class Mesh
{
public:
	Mesh(Vertex* vertArray, int numVerts, unsigned int* indexArray, int numIndices);
	Mesh(const char* objFile);
	~Mesh(void);

	D3D12_VERTEX_BUFFER_VIEW GetVertexBuffer() { return vbView; }
	D3D12_INDEX_BUFFER_VIEW GetIndexBuffer() { return ibView; }
	int GetIndexCount() { return numIndices; }

private:
	int numIndices;

	void CreateBuffers(Vertex* vertArray, int numVerts, unsigned int* indexArray, int numIndices);
	void CalculateTangents(Vertex* verts, int numVerts, unsigned int* indices, int numIndices);

	Microsoft::WRL::ComPtr<ID3D12Resource> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D12Resource> indexBuffer;

	D3D12_VERTEX_BUFFER_VIEW vbView;
	D3D12_INDEX_BUFFER_VIEW ibView;

};

