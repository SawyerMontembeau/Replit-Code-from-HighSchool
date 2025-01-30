using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnManager : MonoBehaviour
{
    private float startDelay = 1.5f;
    private float spawnInterval = 0.5f;
    // Start is called before the first frame update
    void Start()
    {
        InvokeRepeating("spawnRandomAnimal", startDelay, spawnInterval);
    }
    public GameObject[] animalPrefabs;
    private float spawnRangeX = -140;
    private float spawnRangeXUpper = 90;
    private float spawnPosZ = 140;
    private float spawnPosZUpper = -50;
    // Update is called once per frame
    void Update()
    {

    }

    void spawnRandomAnimal()
    {
        int animalIndex = Random.Range(0, animalPrefabs.Length);
        Vector3 spawnPos = new Vector3(Random.Range(spawnRangeX, spawnRangeXUpper), 2, Random.Range(spawnPosZUpper,spawnPosZ));
        Instantiate(animalPrefabs[animalIndex], spawnPos, animalPrefabs[animalIndex].transform.rotation);
    }
}
