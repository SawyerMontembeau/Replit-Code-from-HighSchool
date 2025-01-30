public class DestroyOutOfBounds : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }
    private float topBound = 30;
    private float lowerBound = -10;
    // Update is called once per frame
    void Update()
    {
        if (transform.position.z > topBound)
        {
        Destroy(gameObject);
        }
        else if (transform.position.z < lowerBound)
        {
        Destroy(gameObject);
            Debug.Log("Game Over!");
        }

    }
}
