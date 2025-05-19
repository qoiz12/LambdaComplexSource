namespace Compute
{
constexpr unsigned int gridSizeX = 12;
constexpr unsigned int gridSizeY = 12;
constexpr unsigned int gridSizeZ = 24;
constexpr unsigned int numClusters = gridSizeX * gridSizeY * gridSizeZ;

struct alignas(16) Cluster
{
  glm::vec4 minPoint;
  glm::vec4 maxPoint;
  unsigned int count;
  unsigned int lightIndices[100];
};

unsigned int clusterGridSSBO;

void init_ssbos()
{
  // clusterGridSSBO
  {
    glGenBuffers(1, &clusterGridSSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, clusterGridSSBO);

    // NOTE: we only need to allocate memory. No need for initialization because
    // comp shader builds the AABBs.
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(Cluster) * numClusters,
                 nullptr, GL_STATIC_COPY);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, clusterGridSSBO);
  }
}

Shader clusterComp;

void cull_lights_compute(const Camera &camera)
{
  auto [width, height] = Core::get_framebuffer_size();

  // build AABBs every frame
  clusterComp.use();
  clusterComp.set_float("zNear", camera.near);
  clusterComp.set_float("zFar", camera.far);
  clusterComp.set_mat4("inverseProjection", glm::inverse(camera.projection));
  clusterComp.set_uvec3("gridSize", {gridSizeX, gridSizeY, gridSizeZ});
  clusterComp.set_uvec2("screenDimensions", {width, height});

  glDispatchCompute(gridSizeX, gridSizeY, gridSizeZ);
  glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
}

void init()
{
  init_ssbos();
  // load shaders
  clusterComp = Shader("clusterShader.comp");
}


